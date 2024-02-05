<script>
  // @ts-nocheck

  import { onMount } from "svelte";
  let randomDrink = {};

  async function fetchRandomCocktail() {
    try {
      const response = await fetch("http://localhost:3000/random");
      const data = await response.json();
      randomDrink = data.drinks[0];
      console.log(randomDrink);
      showCard = true;

    } catch (error) {
      console.log(error);
    }
  }

  let showCard = false;

  function getRandomCocktail() {
    fetchRandomCocktail();
  }
</script>

<main>
  <div class="relative z-10">
    <div
      class="absolute inset-x-0 top-1/2 -z-10 flex -translate-y-1/2 justify-center overflow-hidden [mask-image:radial-gradient(50%_45%_at_50%_55%,white,transparent)]"
    >
      <svg
        class="h-[60rem] w-[100rem] flex-none stroke-blue-600 opacity-20"
        aria-hidden="true"
      >
        <defs>
          <pattern
            id="e9033f3e-f665-41a6-84ef-756f6778e6fe"
            width="200"
            height="200"
            x="50%"
            y="50%"
            patternUnits="userSpaceOnUse"
            patternTransform="translate(-100 0)"
          >
            <path d="M.5 200V.5H200" fill="none"></path>
          </pattern>
        </defs>
        <svg x="50%" y="50%" class="overflow-visible fill-blue-50">
          <path
            d="M-300 0h201v201h-201Z M300 200h201v201h-201Z"
            stroke-width="0"
          ></path>
        </svg>
        <rect
          width="100%"
          height="100%"
          stroke-width="0"
          fill="url(#e9033f3e-f665-41a6-84ef-756f6778e6fe)"
        >
        </rect>
      </svg>
    </div>
  </div>
  <div class="h-screen relative z-20 mx-auto max-w-7xl px-6 lg:px-8 mt-32">
    <div class="mx-auto max-w-2xl text-center">
      <h1 class="text-4xl font-bold tracking-tight text-gray-900 sm:text-6xl">
        Cocktail,
        <span class="text-blue-600">scelgo te. </span>
      </h1>
      <h2 class="mt-6 text-lg leading-8 text-gray-600">
        L'importante è che non sia redondi a farlo.
      </h2>

      <div class="mt-10 flex items-center justify-center gap-x-6">
        <button
          class="inline-flex items-center justify-center gap-2 rounded-xl bg-blue-600 px-4 py-3 text-sm font-semibold text-white shadow-sm transition-all duration-150 hover:bg-blue-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-blue-600"
          on:click={getRandomCocktail}
        >
          Scegli un nuovo cocktail
          <svg
            xmlns="http://www.w3.org/2000/svg"
            class="h-4 w-4"
            viewBox="0 0 20 20"
            fill="currentColor"
          >
            <path
              fill-rule="evenodd"
              d="M10.293 3.293a1 1 0 011.414 0l6 6a1 1 0 010 1.414l-6 6a1 1 0 01-1.414-1.414L14.586 11H3a1 1 0 110-2h11.586l-4.293-4.293a1 1 0 010-1.414z"
              clip-rule="evenodd"
            ></path>
          </svg>
        </button>
      </div>

      <div
        class="{showCard ? 'block' : 'hidden'} relative mx-auto mt-10 max-w-lg"
      >
        <div class="w-full rounded-2xl border border-gray-100 shadow">
          <img
            class="w-full h-64 object-cover"
            src={randomDrink.strDrinkThumb}
            alt={randomDrink.strDrink}
          />
          <div class="px-6 py-4">
            <div class="font-bold text-xl mb-2">{randomDrink.strDrink}</div>
            <p class="text-gray-700 text-base">
              {randomDrink.strInstructionsIT}
            </p>
          </div>
          <div class="px-6 pt-4 pb-2">
            <span
              class="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2"
              >{randomDrink.strIngredient1}</span
            >
            <span
              class="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2"
              >{randomDrink.strIngredient2}</span
            >
            <span
              class="inline-block bg-gray-200 rounded-full px-3 py-1 text-sm font-semibold text-gray-700 mr-2 mb-2"
              >{randomDrink.strIngredient3}</span
            >
          </div>
        </div>
      </div>
    </div>
  </div>
</main>
