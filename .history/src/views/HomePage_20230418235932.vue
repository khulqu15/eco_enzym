<template>
  <ion-page>
    <ion-content>
      <div class="bg-base-200 min-h-screen overflow-y-auto pb-24">
        <top-navigation/>
        <div class="px-8">
          <div class="bg-base-100 relative w-full rounded-2xl overflow-hidden">
            <img src="/assets/home.svg" alt="Home" class="absolute top-0 opacity-20 -right-20">
            <div class="w-10/12 p-8 relative">
              <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
              <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
            </div>
            <div class="w-full bg-primary p-2 rounded-2xl"></div>
          </div>
        </div>
        <div class="px-8 mt-8">
          <div v-if="list.length > 0">
            <div v-if="header != ''">
              <h4 class="font-bold text-base-content mb-4">Data EcoEnzyme</h4>
              <draggable v-model="list" class="space-y-5" :header="header" :element="'div'" :options="{handle: '.drag-handle'}" @update="onListUpdate">
                <div v-for="(item, index) in list" class="bg-base-100 p-4 relative grid-cols-1 grid text-base-content rounded-2xl flex justify-between items-center" :key="`data-${index}`">
                  <div class="flex gap-x-3 items-center">
                    <Icon icon="ic:baseline-drag-indicator" class="drag-handle opacity-50" />
                    <h5 class="font-bold">{{ item.name }}</h5>
                  </div>
                  <div class="flex gap-x-2 justify-end items-end">
                    <h4 class="text-primary m-0 font-bold">{{ item.value }}</h4>
                    <p class="text-sm">{{ item.unit }}</p>
                  </div>
                </div>
              </draggable>
            </div>
          </div>
          <div v-else>
            <img src="/assets/loading.svg" alt="Loading">
          </div>
        </div>
      </div>
    </ion-content>
  </ion-page>
</template>


<script lang="ts">
import TopNavigation from '@/components/TopNavigation.vue'
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue';
import { VueDraggableNext } from 'vue-draggable-next'
import { ref, onValue } from 'firebase/database';
import { db } from '@/firebase';

export default defineComponent({
  components: {
    TopNavigation,
    Icon,
    draggable: VueDraggableNext,
  },
  data() {
    return {
      list: [
        { name: '', value: 0.0}
      ],
      header: '',
      databaseData: [],
      data: [
        { name: 'Alcohol (MQ3)', unit: 'Percentage (%)', value: 79 },
        { name: 'Alcohol (MQ303A)', unit: 'Percentage (%)', value: 68 },
        { name: 'PH Meter', unit: null, value: 5.32 },
        { name: 'Ozon', unit: 'PPM', value: 190 },
        { name: 'Temperature', unit: 'Celcius', value: 32 },
      ]
    }
  },
  created() {
    this.header = 'My List';
    const listData: any = localStorage.getItem('data')
    if(!listData) {
      localStorage.setItem('data', JSON.stringify(this.data))
    }
    this.list = JSON.parse(listData)
    console.log(this.list)
    this.getLatestData();
  },
  methods: {
    onListUpdate(event: any) {
      localStorage.setItem('data', JSON.stringify(this.list))
    },
    async getLatestData() {
      const dataRef = ref(db, '/'); // Replace '/' with the path to your data
      onValue(dataRef, (snapshot) => {
        const data = snapshot.val();
        const output: any = Object.entries(data.data).map(([key, value]) => {
          return {[key]: value}
        })
        const limit: any = output.slice(-10)
        const last_data: any = Object.values(limit[limit.length - 1])
        if(this.list) {
          if(this.list.length > 1) {
            const ozon = this.list.find((item) => item.name === "Ozon");
            if (ozon) ozon.value = last_data[0].ozone_ppm as number;

            const temp = this.list.find((item) => item.name === "Temperature");
            if (temp) temp.value = last_data[0].temp_w as number;

            const ph = this.list.find((item) => item.name === "PH Meter");
            if (ph) ph.value = last_data[0].ph ? last_data[0].ph as number : 0;

            const alcohol1 = this.list.find((item) => item.name === "Alcohol (MQ3)");
            if (alcohol1) alcohol1.value = last_data[0].alcohol1 ? last_data[0].alcohol1 as number : 0;

            const alcohol2 = this.list.find((item) => item.name === "Alcohol (MQ303A)");
            if (alcohol2) alcohol2.value = last_data[0].alcohol2 ? last_data[0].alcohol2 as number : 0;
          }
        }
      });
    }
  }
})
</script>
