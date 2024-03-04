<template>
  <ion-page>
      <div class="drawer drawer-mobile">
        <input id="my-drawer-2" type="checkbox" class="drawer-toggle" />
        <div class="drawer-content bg-base-200 flex flex-col items-center justify-center">
          <!-- Page content here -->
          
          <div class="bg-base-200 min-h-screen overflow-y-auto w-full pb-24 relative">
            <label for="my-drawer-2" class="btn absolute left-4 top-4 z-20 btn-primary lg:hidden drawer-button">Menu</label>
            
            <top-navigation/>
            <div class="px-8">
              <div class="bg-base-100 relative w-full rounded-2xl overflow-hidden">
                <img src="/assets/home.svg" alt="Home" class="absolute -top-10 opacity-20 -right-20">
                <div class="w-10/12 p-8 relative">
                  <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
                  <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
                </div>
                <div class="w-full bg-primary p-2 rounded-2xl"></div>
              </div>
            </div>
            <div class="px-8 mt-8">
              <div class="grid md:grid-cols-2 grid-cols-1 gap-4">
                <div>
                  <div class="btn-group mb-3">
                    <button @click="show_data = 'all'" :class="{'btn-active': show_data == 'all', 'bg-base-300 text-base-content': show_data != 'all'}" class="btn">Semua</button>
                    <button @click="show_data = 'fermentation1'" :class="{'btn-active': show_data == 'fermentation1', 'bg-base-300 text-base-content': show_data != 'fermentation1'}" class="btn">Fermentasi 1</button>
                    <button @click="show_data = 'fermentation2'" :class="{'btn-active': show_data == 'fermentation2', 'bg-base-300 text-base-content': show_data != 'fermentation2'}" class="btn">Fermentasi 2</button>
                  </div>
                </div>
                <div class="text-right">
                  <button class="btn btn-primary md:w-auto w-full" @click="exportData(0)">Export All</button>
                </div>
              </div>
              <div v-if="list.length > 0">
                <div v-if="header != ''">
                  <div class="grid gap-4" :class="{'lg:grid-cols-2 grid-cols-1': show_data == 'all', 'grid-cols-1': show_data != 'all'}">
                    <div v-if="show_data == 'all' || show_data == 'fermentation1'">
                      <h4 class="font-bold text-base-content mb-4">Data Fermentasi 1</h4>
                      <div class="w-full mb-2">
                        <Line class="w-full h-64" :data="chartData" :options="chartOptions"></Line>
                      </div>
                      <div class="flex w-full justify-between items-center">
                        <div class="btn-group mb-3 mt-3">
                          <button @click="data1_type = 'newest'" :class="{'btn-active': data1_type == 'newest', 'bg-base-300 text-base-content': data1_type != 'newest'}" class="btn">Terbaru</button>
                          <button @click="data1_type = 'histories'" :class="{'btn-active': data1_type == 'histories', 'bg-base-300 text-base-content': data1_type != 'histories'}" class="btn">Tabel Historis</button>
                        </div>
                        <button class="btn btn-primary" @click="exportData(1)">Export</button>
                      </div>
                      <draggable v-if="data1_type == 'newest'" v-model="last_data_1" class="space-y-5" :header="header" :element="'div'" :options="{handle: '.drag-handle'}" @update="onListUpdate">
                        <div v-for="(item, index) in last_data_1" class="bg-base-100 p-4 relative grid-cols-1 grid text-base-content rounded-2xl flex justify-between items-center" :key="`data-${index}`">
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
                      <div v-if="data1_type == 'histories'">
                        <div class="overflow-x-auto">
                          <table class="table table-compact w-full">
                            <thead>
                              <tr>
                                <th>Timestamp</th>
                                <th>MQ131</th>
                                <th>MQGas</th>
                                <th>Ph</th>
                                <th>Temperature</th>
                              </tr>
                            </thead>
                            <tbody>
                              <tr v-for="(item, index) in data1" :key="`data-${index}`">
                                <td>{{ item.key }}</td>
                                <td>{{ item.MQ131 }}</td>
                                <td>{{ item.MQGas }}</td>
                                <td>{{ item.pH }}</td>
                                <td>{{ item.Temperature }}</td>
                              </tr>
                            </tbody>
                          </table>
                        </div>
                      </div>
                    </div>
                    <div v-if="show_data == 'all' || show_data == 'fermentation2'">
                      <h4 class="font-bold text-base-content mb-4">Data Fermentasi 2</h4>
                      <div class="w-full mb-2">
                        <Line class="w-full h-64" :data="chartData" :options="chartOptions"></Line>
                      </div>
                      <div class="flex items-center justify-between w-full">
                        <div class="btn-group mb-3 mt-3">
                          <button @click="data2_type = 'newest'" :class="{'btn-active': data2_type == 'newest', 'bg-base-300 text-base-content': data2_type != 'newest'}" class="btn">Terbaru</button>
                          <button @click="data2_type = 'histories'" :class="{'btn-active': data2_type == 'histories', 'bg-base-300 text-base-content': data2_type != 'histories'}" class="btn">Tabel Historis</button>
                        </div>
                        <button class="btn btn-primary" @click="exportData(2)">Export</button>
                      </div>
                      <draggable v-if="data2_type == 'newest'" v-model="last_data_2" class="space-y-5" :header="header" :element="'div'" :options="{handle: '.drag-handle'}" @update="onListUpdate">
                        <div v-for="(item, index) in last_data_2" class="bg-base-100 p-4 relative grid-cols-1 grid text-base-content rounded-2xl flex justify-between items-center" :key="`data-${index}`">
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
                      <div v-if="data2_type == 'histories'">
                        <div class="overflow-x-auto">
                          <table class="table table-compact w-full">
                            <thead>
                              <tr>
                                <th>Timestamp</th>
                                <th>MQ131</th>
                                <th>MQGas</th>
                                <th>Ph</th>
                                <th>Temperature</th>
                              </tr>
                            </thead>
                            <tbody>
                              <tr v-for="(item, index) in data2" :key="`data-${index}`">
                                <td>{{ item.key }}</td>
                                <td>{{ item.MQ131 }}</td>
                                <td>{{ item.MQGas }}</td>
                                <td>{{ item.pH }}</td>
                                <td>{{ item.Temperature }}</td>
                              </tr>
                            </tbody>
                          </table>
                        </div>
                      </div>
                    </div>
                    <div v-if="show_data == null">
                      <div class="w-full bg-primary inline-block text-white p-3 rounded-xl">Wait...</div>
                    </div>
                    </div>
                  </div>
              </div>
              <div v-else>
                <img src="/assets/loading.svg" alt="Loading">
              </div>
            </div>
          </div>


        </div> 
        <div class="drawer-side">
          <label for="my-drawer-2" aria-label="close sidebar" class="drawer-overlay"></label> 
          <ul class="menu p-4 w-80 min-h-full bg-base-100 text-base-content">
            <!-- Sidebar content here -->
            <li><a>Sidebar Item 1</a></li>
            <li><a>Sidebar Item 2</a></li>
          </ul>
        
        </div>
      </div>
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
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
} from 'chart.js'
import { Line } from 'vue-chartjs'

ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
)

export default defineComponent({
  name: "HomePage",
  // eslint-disable-next-line
  /* eslint-disable */
  components: {
    IonPage,
    IonContent,
    Line,
    TopNavigation,
    Icon,
    draggable: VueDraggableNext,
  },
  data() {
    return {
      list: [
        { name: '', value: 0.0, unit: ''}
      ],
      data1_type: 'newest',
      data2_type: 'newest',
      data1: [],
      data2: [],
      show_data: null as any,
      chartData: {
        labels: ['2024-01-01', '2024-01-02', '2024-01-03'], // Example dates
        datasets: [{
          label: 'MQ131',
          data: [10, 20, 30],
          backgroundColor: 'rgba(255, 99, 132, 0.5)',
        },
        {
          label: 'MQGas',
          data: [10, 20, 30],
          backgroundColor: 'rgba(100, 150, 255, 0.5)',
        },
        {
          label: 'PH Meter',
          data: [20, 14, 10],
          backgroundColor: 'rgba(100, 230, 100, 0.5)',// Change the color
        },
        {
          label: 'Temperature',
          data: [32, 30, 36],
          backgroundColor: 'rgba(100, 230, 200, 0.5)',// Change the color
        }]
      },
      chartOptions: {
        responsive: true,
        maintainAspectRatio: false,
      },
      header: '',
      databaseData: [],
      last_data_1: [
        { name: 'MQ131', unit: 'PPM', value: 0 },
        { name: 'PH Meter', unit: null, value: 0 },
        { name: 'MQGas', unit: 'PPM', value: 0 },
        { name: 'Temperature', unit: 'Celcius', value: 0 },
      ],
      last_data_2: [
        { name: 'MQ131', unit: 'PPM', value: 0 },
        { name: 'PH Meter', unit: null, value: 0 },
        { name: 'MQGas', unit: 'PPM', value: 0 },
        { name: 'Temperature', unit: 'Celcius', value: 0 },
      ]
    }
  },
  mounted() {
    console.log('FETCH DATA')
  },
  created() {
    this.header = 'My List';
    console.log('FETCH DATA')
    // this.fetchData()
    this.getLatestData();
  },
  methods: {
    exportData(fermentation: number) {
      const data = fermentation == 1 ? this.data1 : fermentation == 2 ? this.data2 : 'all'
      if(data == 'all') {
        const csv = this.data1.map((item: any) => {
          return Object.values(item).join(',')
        }).join('\n')
        const csv2 = this.data2.map((item: any) => {
          return Object.values(item).join(',')
        }).join('\n')
        const csvData = new Blob([csv], { type: 'text/csv' })
        const csvUrl = URL.createObjectURL(csvData)
        const a = document.createElement('a')
        a.href = csvUrl
        a.download = 'data1.csv'
        a.click()
        URL.revokeObjectURL(csvUrl)
        const csvData2 = new Blob([csv2], { type: 'text/csv' })
        const csvUrl2 = URL.createObjectURL(csvData2)
        const a2 = document.createElement('a')
        a2.href = csvUrl2
        a2.download = 'data2.csv'
        a2.click()
        URL.revokeObjectURL(csvUrl2)
      } else {
        const csv = data.map((item: any) => {
          return Object.values(item).join(',')
        }).join('\n')
        const csvData = new Blob([csv], { type: 'text/csv' })
        const csvUrl = URL.createObjectURL(csvData)
        const a = document.createElement('a')
        a.href = csvUrl
        a.download = `data${fermentation}.csv`
        a.click()
        URL.revokeObjectURL(csvUrl)
      }
    },
    onListUpdate(event: any) {
      localStorage.setItem('data', JSON.stringify(this.list))
    },
    fetchData() {
      const data = {
        labels: ['2024-01-01', '2024-01-02', '2024-01-03'], // Example dates
        datasets: [{
          data: [10, 20, 30],
        }]
      };
      console.log("CHART DATA:")
      console.log(this.chartData)
    },
    getLatestData() {
      const dataRef = ref(db, '/'); // Replace '/' with the path to your data
      onValue(dataRef, (snapshot) => {
        const data = snapshot.val();
        const output: any = Object.entries(data.data).map(([key, value]) => {
          return {[key]: value}
        })
        // change object to array {object key, object value 1, object value 2}
        let labels1: any = []
        let mq131_1: any = []
        let mqgas_1: any = []
        let ph_1: any = []
        let temperature_1: any = []

        let table_data = output.map((item: any) => {
          const key = Object.keys(item)[0]
          const value: any = Object.values(item)[0]
          labels1.push(key)
          mq131_1.push(value.MQ131)
          mqgas_1.push(value.MQGas)
          ph_1.push(value.pH)
          temperature_1.push(value.Temperature)
          return { key, ...value }
        })
        const limit: any = output.slice(-10)
        this.chartData.labels = labels1.slice(-10)
        this.chartData.datasets[0].data = mq131_1.slice(-10)
        this.chartData.datasets[1].data = mqgas_1.slice(-10)
        this.chartData.datasets[2].data = ph_1.slice(-10)
        this.chartData.datasets[3].data = temperature_1.slice(-10)

        this.data1 = table_data.slice(-20)
        this.data2 = table_data.slice(-20)
        const last_data: any = Object.values(limit[limit.length - 1])
        setTimeout(() => {
            this.last_data_1[0].value = last_data[0].MQ131 as number;
            this.last_data_1[1].value = last_data[0].Temperature as number;
            this.last_data_1[2].value = last_data[0].pH ? last_data[0].pH as number : 0;
            this.last_data_1[3].value = last_data[0].MQGas ? last_data[0].MQGas as number : 0;


            this.last_data_2[0].value = last_data[0].MQ131 as number;
            this.last_data_2[1].value = last_data[0].Temperature as number;
            this.last_data_2[2].value = last_data[0].pH ? last_data[0].pH as number : 0;
            this.last_data_2[3].value = last_data[0].MQGas ? last_data[0].MQGas as number : 0;
            this.show_data = 'all'
        }, 1000)
      });
    }
  }
})
</script>
