<template>
  <div class="bg-base-200 min-h-screen">
    <top-navigation/>
    <div class="px-8">
      <div class="bg-base-100 relative w-full rounded-2xl overflow-hidden">
        <img src="/assets/home.svg" alt="Home" class="absolute top-0 -right-20">
        <div class="w-8/12 p-8 relative">
          <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
          <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
        </div>
        <div class="w-full bg-primary p-2 rounded-2xl"></div>
      </div>
    </div>
    <div class="px-8 mt-8">
      <div v-if="list.length > 0">
        <div v-if="header != ''">
          <h4 class="font-bold mb-4">Data EcoEnzyme</h4>
          <draggable v-model="list" class="space-y-5" :header="header" :element="'div'" :options="{handle: '.drag-handle'}" @update="onListUpdate">
            <div v-for="(item, index) in list" class="bg-base-100 p-4 text-base-content rounded-2xl flex justify-between items-center" :key="`data-${index}`">
              <div class="flex gap-x-3 items-center">
                <Icon icon="ic:baseline-drag-indicator" class="drag-handle opacity-50" />
                <h5 class="font-bold">{{ item.name }}</h5>
              </div>
              <div class="flex gap-x-2 items-end">
                <h4 class="text-primary m-0 font-bold">{{ item.value }}</h4>
                <p class="text-sm">{{ item.unit }}</p>
                <div class="dropdown dropdown-end">
                  <button class="btn w-8 p-0 btn-ghost">
                    <Icon icon="ion:ellipsis-vertical" />
                  </button>
                  <ul tabindex="0" class="dropdown-content menu p-2 shadow bg-base-100 rounded-box w-52">
                    <li><a class="active:bg-primary">Lihat Semua Data</a></li>
                  </ul>
                </div>
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
</template>


<script lang="ts">
import TopNavigation from '@/components/TopNavigation.vue'
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue';
import { VueDraggableNext } from 'vue-draggable-next'

export default defineComponent({
  components: {
    TopNavigation,
    Icon,
    draggable: VueDraggableNext,
  },
  data() {
    return {
      list: [],
      header: '',
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
  },
  methods: {
    onListUpdate(event: any) {
      localStorage.setItem('data', JSON.stringify(this.list))
    }
  }
})
</script>
