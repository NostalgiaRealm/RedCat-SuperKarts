/*
 * FUN_00490ce0 at 00490ce0
 * undefined FUN_00490ce0(void)
 * Address ranges: 00490ce0-00490d3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00490ce0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(DAT_006a5c38 + iVar1 + iVar1 * 0xa8);
  iVar1 = DAT_006a5c38 + iVar1 + iVar1 * 0xa8;
  if (iVar2 == 1) {
    return *(undefined4 *)(iVar1 + 0x99);
  }
  if (iVar2 != 2) {
    FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
    return 0;
  }
  return *(undefined4 *)
          (*(int *)(*(int *)(*(int *)(iVar1 + 4) * 9 + 4 + DAT_006a5f78) + *(int *)(iVar1 + 8) * 4)
           * 0x10 + DAT_006a5f30);
}

