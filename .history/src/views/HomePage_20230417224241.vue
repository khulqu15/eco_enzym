<template>
  <div class="bg-base-200 min-h-screen">
    <top-navigation/>
    <div class="px-8">
      <div class="bg-base-100 r w-full rounded-2xl overflow-hidden">
        <div class="w-8/12 p-8">
          <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
          <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
        </div>
        <div class="w-full bg-primary p-2 rounded-2xl"></div>
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
  }
})
</script>
