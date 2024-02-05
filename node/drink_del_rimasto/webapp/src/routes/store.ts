import {
  derived,
  writable,
} from 'svelte/store';

export const apiData = writable([]);

export const drinkNames = derived(apiData, ($apiData) => {
    return $apiData;
  
});