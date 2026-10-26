/*
 * FUN_00408bc6 at 00408bc6
 * undefined __stdcall FUN_00408bc6(void)
 * Address ranges: 00408bc6-00408c10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408bc6(void)

{
  byte in_AL;
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_0040f0ea;
    bVar1 = in_AL;
    for (pcVar3 = &DAT_0040f0e4; pcVar3 < &DAT_0040f0ea; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && ((byte)pcVar3[1] <= bVar1)) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_0040f0ea) break;
    if (*(code **)(pcVar2 + 2) != (code *)0x0) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}

