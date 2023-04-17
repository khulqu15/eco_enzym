<template>
    <div class="flex px-8 py-4 justify-between items-center">
        <div>
            <button class="btn btn-ghost">
                <Icon icon="ri:notification-2-line" class="text-base-content text-xl"/>
            </button>
        </div>
        <div>
            <div class="avatar">
                <div class="w-24 mask mask-squircle">
                    <img src="/images/stock/photo-1534528741775-53994a69daeb.jpg" />
                </div>
            </div>
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
