<template>
    <div class="flex px-8 py-4 justify-between items-center">
        <div>
            <button class="btn btn-ghost opacity-0">
                <Icon icon="ri:notification-2-line" class="text-base-content text-xl"/>
            </button>
        </div>
        <div>
            <div @click="$router.push({name: 'Profile'})" class="avatar btn btn-ghost px-0 hover:bg-base-200">
                <div class="w-12 mask mask-squircle">
                    <img v-if="isEmpty(user)" :src="`${user.photoURL}`" alt="Photo profile"/>
                </div>
            </div>
        </div>
    </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import { Icon } from '@iconify/vue'
import { onAuthStateChanged } from 'firebase/auth'
import { auth } from '@/firebase'

export default defineComponent({
    components: { Icon },
    data() {
        return {
            user: {}
        }
    },
    created() {
        onAuthStateChanged(auth, (user) => {
            if (user) this.user = user
            console.log(this.user)
        })
    },
    methods: {
        isEmpty(obj: object): boolean {
           return Object.keys(obj).length === 0 && obj.constructor === Object;
        }
    }

})
</script>
