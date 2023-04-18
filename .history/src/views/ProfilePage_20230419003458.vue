<template>
  <ion-page>
    <ion-content>
        <div class="bg-base-200 min-h-screen">
            <div class="px-8 py-8">
            <div class="flex justify-between items-center">
                <button @click="$router.push({name: 'Home'})" class="btn btn-ghost">
                    <Icon icon="solar:home-smile-angle-bold-duotone" class="text-3xl"/>
                    Kembali
                </button>
                <h4 class="font-bold m-0 text-base-content">{{ !isEmpty(user) ? 'Profilku' : 'Pengaturan' }}</h4>
            </div>
            <div v-if="!isEmpty(user)" class="bg-base-100 relative w-full rounded-2xl mt-6 overflow-hidden">
                <div class="w-full p-8 relative items-center flex gap-x-4">
                    <div @click="$router.push({name: 'Profile'})" class="avatar px-0 hover:bg-base-200">
                        <div class="w-16 mask mask-squircle">
                            <img :src="`${user.photoURL}`" alt="Photo profile"/>
                        </div>
                    </div>
                    <div>
                        <h5 class="m-0 font-bold">{{ user.displayName }}</h5>
                        <p class="text-base-content text-sm">{{ user.email }}</p>
                    </div>
                </div>
                <div class="w-full bg-primary p-2 rounded-2xl"></div>
            </div>
            <div @click="changeTheme()" class="btn text-sm bg-base-300 h-24 w-full p-6 rounded-2xl mt-4 flex items-center justify-between">
                <div class="flex gap-x-3 text-base-content items-center">
                    <Icon class="text-3xl text-primary" icon="pajamas:appearance" />
                    <p>Theme: {{ currentTheme }}</p>
                </div>
                <div class="flex justify-end w-full">
                    <p class="text-sm text-end text-base-content">Click to change</p>
                </div>
            </div>
            </div>
            <div class="w-full bg-base-100 fixed bottom-0 left-0 w-full p-6 rounded-t-2xl">
                <button @click="onLogout()" class="btn w-full bg-red-500 text-white">Logout</button>
            </div>
        </div>
    </ion-content>
  </ion-page>
</template>


<script lang="ts">
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue';
import { IonContent, IonPage } from '@ionic/vue'
import { onAuthStateChanged, signOut } from 'firebase/auth'
import { auth } from '@/firebase'

export default defineComponent({
  data() {
    return {
        user: {},
        selectedTheme: 0,
        currentTheme: 'light',
        themes: ['light', 'dark', 'cupcake', 'bumblebee', 'emerald', 'halloween', 'forest', 'aqua', 'black', 'coffee']
    }
  },
  created() {
    onAuthStateChanged(auth, (user) => {
        if (user) this.user = user
    })
    console.log(this.user)
    const localTheme: any = localStorage.getItem('theme')
    if(!localTheme) 
        this.currentTheme = 'light'
    else
        this.currentTheme = localTheme
  },
  components: {
    Icon,
    IonPage,
    IonContent,
  },
  methods: {
    isEmpty(obj: object): boolean {
        return Object.keys(obj).length === 0 && obj.constructor === Object;
    },
    changeTheme() {
        if(this.selectedTheme >= 9)
            this.selectedTheme = 0
        
        this.selectedTheme += 1
        localStorage.setItem('theme', this.themes[this.selectedTheme])
        document.documentElement.dataset.theme = this.themes[this.selectedTheme]
        this.currentTheme = this.themes[this.selectedTheme]
    },
    async onLogout() {
        try {
            await signOut(auth)
            this.$router.push({name: 'Start'})
        } catch (error) {
            console.error('Error signing out:', error)
        }
    }
  }
})
</script>
