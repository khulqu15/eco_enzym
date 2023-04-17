<template>
  <ion-app>
    <ion-router-outlet :key="routerViewKey"/>
  </ion-app>
</template>

<script lang="ts">
import { defineComponent, ref } from 'vue';
import { IonApp, IonRouterOutlet } from '@ionic/vue';
export default {
  components: {
    IonRouterOutlet,
    IonApp
  },
  setup() {
    const routerViewKey = ref(0);
    return { routerViewKey };
  },
  watch: {
    $route() {
      this.routerViewKey += 1;
    },
  },
}
</script>
