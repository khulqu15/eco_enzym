<template>
  <div class="bg-base-200 min-h-screen">
    <div class="px-8 py-8">
      <div class="flex justify-between items-center">
        <button class="btn btn-ghost">
            <Icon icon="solar:home-smile-angle-bold-duotone" class="text-3xl"/>
            Kembali
        </button>
        <h4 class="font-bold m-0 text-base-content">Profilku</h4>
      </div>
      <div class="bg-base-100 relative w-full rounded-2xl overflow-hidden">
        <div class="w-full p-8 relative items-center flex gap-x-2">
            <div @click="$router.push({name: 'Profile'})" class="avatar btn btn-ghost px-0 hover:bg-base-200">
                <div class="w-24 mask mask-squircle">
                    <img src="https://randomuser.me/api/portraits/women/60.jpg" />
                </div>
            </div>
            <div>
                <h4 class="text-primary m-0 font-bold">Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</h4>
                <p class="text-base-content mt-3">Mempermudah Monitoring Sensor IoT dengan Tampilan User-Friendly</p>
            </div>
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
