<script lang="ts">
import ModeToggle from "$lib/components/ModeToggle.svelte";

let input_content = $state("");

function play_sound() {
  const sound = new Audio("1.wav");
  sound.play();
}

function handle_submit(event: SubmitEvent) {
  event.preventDefault();
  play_sound();
  input_content = "";
}

</script>

<div class="w-dvw h-dvh flex flex-col">
  <nav class="w-full flex justify-end p-4">
    <ModeToggle />
  </nav>
  <main class="flex size-full justify-center items-center">
    <form onsubmit={handle_submit} class="min-w-32 max-w-lg h-16 w-[50%] ">
      <input
        type="text"
        class="bg-foreground outline-4 outline-accent text-accent size-full font-bold p-2 text-4xl dark:text-background"
        bind:value={input_content}
      />
    </form>
  </main>
</div>
