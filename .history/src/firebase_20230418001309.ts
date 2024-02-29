import { initializeApp } from 'firebase/app'
import { getAuth } from 'firebase/auth'

const firebaseConfig = {
    apiKey: "AIzaSyC-mHNOM1cUsizZqeMH9YzmyiKAljTO6pI",
    authDomain: "ecoenzym-d56ec.firebaseapp.com",
    databaseURL: "https://ecoenzym-d56ec-default-rtdb.asia-southeast1.firebasedatabase.app",
    projectId: "ecoenzym-d56ec",
    storageBucket: "ecoenzym-d56ec.appspot.com",
    messagingSenderId: "101999972533",
    appId: "1:101999972533:web:5e70ee657ffbfdc93b2efc",
    measurementId: "G-562K6V393V"
}

const app = initializeApp(firebaseConfig)
const auth = getAuth(app)

export { app, auth }
