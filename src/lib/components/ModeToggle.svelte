<script lang="ts">
  import { mode, toggleMode } from "mode-watcher";
  import { Sun, Moon } from "@lucide/svelte";
</script>

<button onclick={toggleMode} title="toggle mode" class="cursor-pointer">
  {#if mode.current === "dark"}
    <Sun />
  {:else}
    <Moon />
  {/if}
</button>
