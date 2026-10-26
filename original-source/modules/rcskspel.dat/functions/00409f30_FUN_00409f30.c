/*
 * FUN_00409f30 at 00409f30
 * undefined FUN_00409f30(void)
 * Address ranges: 00409f30-00409fde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00409f30(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = (int *)(*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0xc + DAT_0067ee20);
  local_c = *(undefined4 *)
             (*(int *)(*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
              + DAT_006a5c38 + 0x50);
  local_8 = *(undefined4 *)(*piVar1 * 0xa9 + DAT_006a5c38 + 0x54);
  local_4 = *(undefined4 *)(DAT_006a5c38 + *piVar1 * 0xa9 + 0x58);
  iVar2 = FUN_00401320((&DAT_00503ef0)[param_1 * 0x47],&local_c);
  if ((0x708 < iVar2) && (iVar2 < 0x898)) {
    return 1;
  }
  return 0;
}

