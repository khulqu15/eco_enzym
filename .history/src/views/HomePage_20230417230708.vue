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
        <div v-for="(item, index) in list" class="bg-base-100 p-4 text-base-content rounded-2xl flex justify-between items-center" :key="`data-${index}`">
          <div class="flex gap-x-3 items-center">
            <Icon icon="ic:baseline-drag-indicator" />
            <h5 class="font-bold">{{ item.name }}</h5>
          </div>
          <div class="flex gap-x-3 items-center">
            <h5 class="text-primary font-bold">{{ item.value }}</h5>
            <p>{{ item.value }}</p>
          </div>
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
export default defineComponent({
  components: {
    TopNavigation,
    Icon,
  },
  data() {
    return {
      list: [],
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
    const listData: any = localStorage.getItem('data')
    if(!listData) {
      localStorage.setItem('data', JSON.stringify(this.data))
    }
    this.list = JSON.parse(listData)
    console.log(this.list)
  }
})
</script>
