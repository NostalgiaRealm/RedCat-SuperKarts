/*
 * FUN_00431210 at 00431210
 * undefined FUN_00431210(void)
 * Address ranges: 00431210-00431295
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00431210(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_84;
  char local_80 [128];
  
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = *(undefined1 **)(param_1 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar3,puVar2,local_80,0x7f);
  iVar4 = -1;
  pcVar5 = local_80;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    iVar4 = FUN_004bf458(local_80,&DAT_004eb210,&local_84);
    if (iVar4 != 0) {
      *param_3 = local_84;
      return 1;
    }
  }
  return 0;
}

