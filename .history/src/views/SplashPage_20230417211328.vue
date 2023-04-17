<template>
  <div id="splash-content" class="min-h-screen bg-primary grid grid-cols-1 items-center justify-center">
    <div id="splash-image" class="w-3/4 mx-auto d-inline-block text-center animate__animated animate__fadeIn">
      <img src="/assets/icon/icon.png" class="w-24 mx-auto" alt="Logo">
      <h2 class="text-white font-bold">ECONENZYME</h2>
    </div>
  </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
export default defineComponent({
    created() {
        setTimeout(() => {
            const splashImage = document.getElementById('splash-image')?.classList
            splashImage?.remove('animate__animated', 'animate__fadeIn')
            splashImage?.add('animate__animated', 'animate__fadeOut')
        }, 1500)
        setTimeout(() => {
            const splashContent = document.getElementById('splash-content')?.classList
            splashContent?.add('animate__animated', 'animate__fadeOut')
            this.$router.push({name: 'Home'})
        }, 2000)
    },
})
</script>