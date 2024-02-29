import { createRouter, createWebHistory } from '@ionic/vue-router';
import { RouteRecordRaw } from 'vue-router';
import HomePage from '../views/HomePage.vue'
import SplashPage from '../views/SplashPage.vue'
import StartPage from '../views/StartPage.vue'

const routes: Array<RouteRecordRaw> = [
  {
    path: '/',
    name: 'Splash',
    component: SplashPage
  },
  {
    path: '/home',
    name: 'Home',
    component: HomePage
  },
  {
    path: '/start',
    name: 'Start',
    component: HomePage
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router
