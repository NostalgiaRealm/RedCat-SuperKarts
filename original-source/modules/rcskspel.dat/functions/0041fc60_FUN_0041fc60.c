/*
 * FUN_0041fc60 at 0041fc60
 * undefined FUN_0041fc60(void)
 * Address ranges: 0041fc60-0041fd86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041fc60(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [32];
  
  FUN_00498b50(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20),0,0x41a00000,0);
  iVar2 = *(int *)(DAT_0068021c + 0xc + *(int *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20) * 4);
  iVar1 = DAT_00680b28 + 0x24 + iVar2 * 0x984;
  FUN_004988a0(*(undefined4 *)(DAT_00680b28 + 0x24 + iVar2 * 0x984),*(float *)(iVar1 + 4) + 40.0,
               *(undefined4 *)(iVar1 + 8));
  FUN_00498c00();
  FUN_0041d6c0(5);
  if ((-1 < DAT_0053be60) && (DAT_0053be60 < 4)) {
    FUN_004be8cb(auStack_20,0x1d,&DAT_004e3a84,DAT_0053be60 + 1);
  }
  FUN_0049e9b0(0xffffffff);
  return;
}

