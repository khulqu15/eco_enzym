<template>
  <div id="splash-content" class="min-h-screen bg-base-200 grid grid-cols-1 items-center justify-center">
    <div class="fixed left-0 top-0 w-full p-3">
        <img src="/assets/icon/favicon.png" class="w-12 mx-auto" alt="">
    </div>
    <div class="w-10/12 px-8">
        <img src="/assets/start.svg" class="w-3/4">
        <h3 class="text-base-content font-bold">Aplikasi Monitoring Sensor IoT Interaktif dan Ramah Lingkungan</h3>
        <p>Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</p>
    </div>
    <div class="fixed left-0 bottom-0 w-full p-6 bg-base-100 rounded-t-2xl">
        <button @click="loginGoogle()" class="btn bg-primary w-full">Mulai Sekarang</button>
    </div>
  </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
export default defineComponent({
    methods: {
        loginGoogle() {
            this.$router.push({name: 'Home'})
        }
    }
})
</script>