<template>
  <div class="bg-base-200 min-h-screen">
    <div class="px-8 py-8">
      <div class="flex justify-between items-center">
        <button class="btn btn-ghost">
            <Icon icon="solar:home-smile-angle-bold-duotone" class="text-3xl"/>
            Kembali
        </button>
        <h4 class="font-bold m-0">Profilku</h4>
      </div>
      <div class="bg-base-100 relative w-full rounded-2xl overflow-hidden">
        <img src="/assets/home.svg" alt="Home" class="absolute top-0 -right-20">
        <div class="w-8/12 p-8 relative">
          <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
          <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
        </div>
        <div class="w-full bg-primary p-2 rounded-2xl"></div>
      </div>
    </div>
  </div>
</template>


<script lang="ts">
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue';

export default defineComponent({
  data() {
    return {
     
    }
  },
  components: {
    Icon,
  },
})
</script>
