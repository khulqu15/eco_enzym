<template>
    <ion-page>
        <ion-content>
            <button class="btn btn-primary">Test</button>
        </ion-content>
    </ion-page>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import { IonPage, IonContent } from '@ionic/vue'
export default defineComponent({
    components: {
        IonPage,
        IonContent,
    }
})
</script>