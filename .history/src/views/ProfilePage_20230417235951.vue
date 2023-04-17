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
      <div @click="changeTheme()" class="bg-base-300 w-full p-6 rounded-2xl mt-4 flex items-center justify-between">
        <div class="flex gap-x-3 text-base-content items-center">
            <Icon class="text-3xl text-primary" icon="pajamas:appearance" />
            <p>Theme: {{ themes[selectedTheme] }}</p>
        </div>
        <div>
            <p class="text-sm text-base-content">Click to change</p>
        </div>
      </div>
    </div>
    <div class="w-full bg-base-100 fixed bottom-0 left-0 w-full p-6 rounded-t-2xl">
        <button class="btn w-full bg-red-500">Logout</button>
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
  methods: {
    changeTheme() {
        if(this.selectedTheme >= 9)
            this.selectedTheme = 0
        
        this.selectedTheme += 1
        localStorage.setItem('theme', this.themes[this.selectedTheme])
        document.documentElement.dataset.theme = this.themes[this.selectedTheme]
    }
  }
})
</script>
