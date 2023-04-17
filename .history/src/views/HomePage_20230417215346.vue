<template>
  <div class="bg-base-200 min-h-screen">
    <top-navigation/>
    <div class="px-8">
      <div class="bg-base-100 w-full p-8 rounded-2xl">
        <div class="w-10/12">
          <h3 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h3>
        </div>
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
