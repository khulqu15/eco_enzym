<template>
    <div class="flex px-8 py-4 justify-content-between items-center">
        <div>
            <button class="btn btn-ghost">
                <Icon icon="ri:notification-2-line" class="text-base-content"/>
            </button>
        </div>
    </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue'

export default defineComponent({
    components: { Icon }
})
</script>
