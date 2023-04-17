module.exports = {
  mode: 'jit',
  purge: [
    './index.html',
    './src/**/*.{vue,js,ts,jsx,tsx}'
  ],
  theme: {
    colors: {
      primary: '#00AA13',
    },
    extend: {},
  },
  variants: {},
  plugins: [
    require('daisyui')
  ],
}
