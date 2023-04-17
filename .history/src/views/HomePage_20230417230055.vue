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
      <div v-if="list.length > 0" class="space-y-5">
        <div v-for="(item, index) in list" class="bg-base-100 p-4 rounded-2xl" :key="`data-${index}`">
          {{ item.name }}
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
export default defineComponent({
  components: {
    TopNavigation
  },
  data() {
    return {
      list: [],
      data: [
        { name: 'Alcohol (MQ3)', unit: 'Percentage (%)', value: 0 },
        { name: 'Alcohol (MQ303A)', unit: 'Percentage (%)', value: 0 },
        { name: 'PH Meter', unit: null, value: 0 },
        { name: 'Ozon', unit: 'PPM', value: 0 },
        { name: 'Ozon', unit: 'PPM', value: 0 },
      ]
    }
  },
  created() {
    const listData: any = localStorage.getItem('data')
    if(!listData) {
      localStorage.setItem('data', JSON.stringify(this.data))
    } else {
      this.list = JSON.parse(listData)
      console.log(this.list)
    }
  }
})
</script>
