/*
 * FUN_004077a0 at 004077a0
 * undefined __stdcall FUN_004077a0(void)
 * Address ranges: 004077a0-00407800
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004077a0(void)

{
  int in_EAX;
  
  if (*(HWAVEOUT *)(in_EAX + 0x38) != (HWAVEOUT)0x0) {
    waveOutReset(*(HWAVEOUT *)(in_EAX + 0x38));
    do {
      do {
      } while (((*(LPWAVEHDR *)(in_EAX + 0x54))->dwFlags & 1) == 0);
    } while ((*(byte *)(*(int *)(in_EAX + 0x58) + 0x10) & 1) == 0);
    waveOutUnprepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    waveOutUnprepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x58),0x20);
    waveOutClose(*(HWAVEOUT *)(in_EAX + 0x38));
    *(undefined4 *)(in_EAX + 0x38) = 0;
  }
  return;
}

