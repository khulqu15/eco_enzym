<template>
  <div class="bg-base-200 min-h-screen">
    <div class="px-8 py-8">
      <div class="flex justify-between items-center">
        <button @click="$router.push({name: 'Home'})" class="btn btn-ghost">
            <Icon icon="solar:home-smile-angle-bold-duotone" class="text-3xl"/>
            Kembali
        </button>
        <h4 class="font-bold m-0 text-base-content">Profilku</h4>
      </div>
      <div class="bg-base-100 relative w-full rounded-2xl mt-6 overflow-hidden">
        <div class="w-full p-8 relative items-center flex gap-x-4">
            <div @click="$router.push({name: 'Profile'})" class="avatar px-0 hover:bg-base-200">
                <div class="w-20 mask mask-squircle">
                    <img src="https://randomuser.me/api/portraits/women/60.jpg" />
                </div>
            </div>
            <div>
                <h3 class="m-0 font-bold">Mohammad Khusnul Khuluq</h3>
                <p class="text-base-content">khusnul.ninno15@gmail.com</p>
            </div>
        </div>
        <div class="w-full bg-primary p-2 rounded-2xl"></div>
      </div>
      <div class="bg-base-300"></div>
    </div>
  </div>
</template>


<script lang="ts">
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue';

export default defineComponent({
  data() {
    return {
        selectedTheme: 0,
        themes: ['light', 'dark', 'cupcake', 'bumblebee', 'emerald', 'halloween', 'forest', 'aqua', 'black', 'coffee']
    }
  },
  components: {
    Icon,
  },
})
</script>
