/*
 * FUN_00464dd0 at 00464dd0
 * undefined FUN_00464dd0(void)
 * Address ranges: 00464dd0-00464e8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464dd0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00464c80(param_1);
  iVar1 = FUN_00459c80();
  FUN_00464c80(param_1);
  iVar2 = FUN_00459cb0();
  *(undefined4 *)(DAT_006a5c38 + iVar2 * 0xa9 + 0x99) =
       *(undefined4 *)
        (*(int *)(*(int *)(iVar1 * 9 + 4 + DAT_006a5f78) + param_2 * 4) * 0x10 + DAT_006a5f30);
  FUN_00464c80(param_1);
  iVar1 = FUN_00459c80();
  FUN_00464c80(param_1);
  iVar2 = FUN_00459cb0();
  *(undefined4 *)(DAT_006a5c38 + iVar2 * 0xa9 + 0x95) =
       *(undefined4 *)
        (*(int *)(*(int *)(iVar1 * 9 + 4 + DAT_006a5f78) + param_2 * 4) * 0x10 + 4 + DAT_006a5f30);
  return;
}

