/*
 * FUN_00463fb0 at 00463fb0
 * undefined FUN_00463fb0(void)
 * Address ranges: 00463fb0-00464045;00464047-00464051
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00463fb0(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *pcVar6;
  float local_88;
  char *local_84;
  char local_80 [128];
  
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar4 = *(undefined1 **)(param_1 + 4);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar4,puVar2,local_80,0x7f);
  iVar3 = FUN_004bf458(local_80,&DAT_004f4064,&local_88);
  if (iVar3 != 0) {
    return (float10)local_88;
  }
  iVar3 = -1;
  pcVar5 = local_80;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar6 + -1) = s___Bad_float_004f4068._0_4_;
  *(undefined4 *)(pcVar6 + 3) = s___Bad_float_004f4068._4_4_;
  local_84 = local_80;
  *(undefined4 *)(pcVar6 + 7) = s___Bad_float_004f4068._8_4_;
  pcVar6[0xb] = s___Bad_float_004f4068[0xc];
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_84,&DAT_004d5538);
}

