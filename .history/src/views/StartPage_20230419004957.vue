<template>
  <ion-page>
    <ion-content>
        <div id="splash-content" class="min-h-screen bg-base-200 pb-24 grid grid-cols-1 items-center justify-center">
            <div class="fixed left-0 top-0 w-full p-3">
                <img src="/assets/icon/favicon.png" class="w-12 mx-auto" alt="">
            </div>
            <div class="w-10/12 px-8">
                <img src="/assets/start.svg" class="w-3/4">
                <h3 class="text-base-content font-bold">Aplikasi Monitoring Sensor IoT Interaktif dan Ramah Lingkungan</h3>
                <p>Monitoring Sensor IoT Secara Real-Time dengan EcoEnzyme</p>
            </div>
            <div class="fixed left-0 bottom-0 w-full p-6 bg-base-100 rounded-t-2xl">
                <button @click="loginGoogle()" class="btn bg-primary w-full text-white">Login</button>
                <button @click="$router.push({name: 'Home'})" class="btn mt-3 bg-ghost w-full text-white">Skip</button>
            </div>
        </div>
    </ion-content>
  </ion-page>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import { auth } from '@/firebase'
import { IonPage, IonContent } from '@ionic/vue'
import { GoogleAuthProvider, signInWithPopup } from 'firebase/auth'

export default defineComponent({
    components: {
        IonPage, IonContent,
    },
    methods: {
        async loginGoogle() {
            try {
                const provider = new GoogleAuthProvider()
                await signInWithPopup(auth, provider)
                // this.$router.push({name: 'Home'})
                window.location.href = '/home';
            } catch (error) {
                console.error('Error logging in with Google:', error)
            }
        }
    }
})
</script>