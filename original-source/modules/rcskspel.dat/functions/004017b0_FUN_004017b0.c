/*
 * FUN_004017b0 at 004017b0
 * undefined FUN_004017b0(void)
 * Address ranges: 004017b0-00401846
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004017b0(int param_1)

{
  int iVar1;
  undefined4 auStack_c [2];
  undefined4 uStack_4;
  
  auStack_c[0] = *(undefined4 *)
                  (*(int *)(*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0xc + DAT_0067ee20) *
                   0xa9 + DAT_006a5c38 + 0x50);
  uStack_4 = *(undefined4 *)
              (DAT_006a5c38 +
               *(int *)(*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0xc + DAT_0067ee20) *
               0xa9 + 0x58);
  iVar1 = FUN_00401320((&DAT_00503ef0)[param_1 * 0x47],auStack_c);
  if ((0x6a4 < iVar1) && (iVar1 < 0x8fc)) {
    return 1;
  }
  return 0;
}

