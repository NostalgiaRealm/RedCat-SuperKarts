/*
 * FUN_004182f0 at 004182f0
 * undefined FUN_004182f0(void)
 * Address ranges: 004182f0-004183c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004182f0(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  CHAR local_60 [16];
  undefined1 local_50 [16];
  char local_40 [64];
  
  FUN_004b1f10(param_2,s_GearA_004e13ec,local_40,0x3f);
  iVar4 = -1;
  pcVar5 = local_40;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00492fe0(iVar4 != -2,s__s___d__No_sound_type_name_found_004e13f4);
  iVar4 = FUN_0049de80(local_40);
  param_1[9] = iVar4;
  iVar4 = FUN_0049dd20(iVar4);
  puVar2 = *(undefined1 **)(iVar4 + 0x1c);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  uVar3 = FUN_004b51e0(puVar2,0);
  *(undefined4 *)(iVar4 + 0x38) = uVar3;
  iVar4 = 0;
  if (0 < *param_1) {
    do {
      wsprintfA(local_60,&DAT_004e1430,s_GearA_004e1428,iVar4);
      FUN_004181d0(param_2,local_60,local_50);
      FUN_00418ef0(*(undefined4 *)(param_1[0xb] + 8),1,local_50);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *param_1);
  }
  return;
}

