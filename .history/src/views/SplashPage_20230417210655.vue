<template>
    <div class="min-h-screen bg-primary grid grid-cols-1 items-center justify-center">
        <div class="w-3/4 mx-auto d-inline-block text-center">
            <img src="/assets/icon/icon.png" class="w-24 mx-auto" alt="Logo">
            <h2 class="text-white font-bold">ECONENZYME</h2>
        </div>
    </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
// import { IonPage, IonContent } from '@ionic/vue'
export default defineComponent({
})
</script>

<style>
.splash-screen {
    background-color: #00AA13;
    position: fixed;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    display: flex;
    justify-content: center;
    align-items: center;
    z-index: 1000;
    animation: splash-screen 3s forwards;
}

@keyframes splash-screen {
    0% {
    opacity: 1;
    }
    100% {
    opacity: 0;
    visibility: hidden;
    }
}
  </style>