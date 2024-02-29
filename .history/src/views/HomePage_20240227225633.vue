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
              <div class="w-full">
                <LineChart class="w-full h-64" :data="chartData" :options="chartOptions"></LineChart>
              </div>
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
import { IonPage, IonContent } from '@ionic/vue'
import { db } from '@/firebase';
import { Line } from 'vue-chartjs';
import { Chart as ChartJS, Title, ChartOptions, ChartData, Tooltip, Legend, BarElement, CategoryScale, LinearScale } from 'chart.js'
ChartJS.register(Title, Tooltip, Legend, BarElement, CategoryScale, LinearScale)


export default defineComponent({
  name: "HomePage",
  components: {
    IonPage,
    IonContent,
    LineChart: Line,
    TopNavigation,
    Icon,
    draggable: VueDraggableNext,
  },
  data() {
    return {
      list: [
        { name: '', value: 0.0, unit: ''}
      ],
      chartData: {
        labels: ['2024-01-01', '2024-01-02', '2024-01-03'], // Example dates
        datasets: [{
          label: 'My Time Series',
          data: [10, 20, 30], // Example data points
          fill: false,
          borderColor: 'blue'
        }]
      } as ChartData<'line'>,
      chartOptions: {
        responsive: true,
      } as ChartOptions<'line'>,
      header: '',
      databaseData: [],
      data: [
        // { name: 'Alcohol (MQ3)', unit: 'Percentage (%)', value: 0 },
        { name: 'Alcohol (MQ303A)', unit: 'Percentage (%)', value: 0 },
        { name: 'PH Meter', unit: null, value: 0 },
        { name: 'Ozon', unit: 'PPM', value: 0 },
        { name: 'Temperature', unit: 'Celcius', value: 0 },
      ]
    }
  },
  mounted() {
    console.log('FETCH DATA')
  },
  created() {
    this.header = 'My List';
    const listData: any = localStorage.getItem('data')
    if(!listData) {
      localStorage.setItem('data', JSON.stringify(this.data))
    }
    this.list = JSON.parse(listData)
    console.log(this.list)
    console.log('FETCH DATA')
    this.fetchData()
    this.getLatestData();
  },
  methods: {
    onListUpdate(event: any) {
      localStorage.setItem('data', JSON.stringify(this.list))
    },
    fetchData() {
      const data = {
        labels: ['2024-01-01', '2024-01-02', '2024-01-03'], // Example dates
        datasets: [{
          label: 'My Time Series',
          data: [10, 20, 30],
          fill: false,
          borderColor: 'blue'
        }]
      };
      console.log("CHART DATA:")
      console.log(this.chartData)
      this.chartData = data;
    },
    getLatestData() {
      const dataRef = ref(db, '/'); // Replace '/' with the path to your data
      onValue(dataRef, (snapshot) => {
        const data = snapshot.val();
        const output: any = Object.entries(data.data).map(([key, value]) => {
          return {[key]: value}
        })
        const limit: any = output.slice(-10)
        const last_data: any = Object.values(limit[limit.length - 1])
        setTimeout(() => {
          if(this.list != null && this.list != undefined) {
            if(this.list.length != null && this.list.length > 1) {
              const ozon = this.list.find((item) => item.name === "Ozon");
              if (ozon) ozon.value = last_data[0].ozone_ppm as number;

              const temp = this.list.find((item) => item.name === "Temperature");
              if (temp) temp.value = last_data[0].temperature as number;

              const ph = this.list.find((item) => item.name === "PH Meter");
              if (ph) ph.value = last_data[0].ph ? last_data[0].ph as number : 0;

              const alcohol1 = this.list.find((item) => item.name === "Alcohol (MQ3)");
              if (alcohol1) alcohol1.value = last_data[0].alcohol1 ? last_data[0].alcohol1 as number : 0;

              const alcohol2 = this.list.find((item) => item.name === "Alcohol (MQ303A)");
              if (alcohol2) alcohol2.value = last_data[0].alcohol2 ? last_data[0].alcohol2 as number : 0;
            }
          }
        }, 1000)
      });
    }
  }
})
</script>
