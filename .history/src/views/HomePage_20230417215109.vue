<template>
  <div class="bg-base-200 min-h-screen">
    <top-navigation/>
    <div class="px-8"></div>
  </div>
</template>


<script lang="ts">
import TopNavigation from '@/components/TopNavigation.vue'
import { defineComponent } from 'vue'
export default defineComponent({
  components: {
    TopNavigation
  }
})
</script>
