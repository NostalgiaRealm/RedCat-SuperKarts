/*
 * FUN_00440e50 at 00440e50
 * undefined FUN_00440e50(void)
 * Address ranges: 00440e50-00440ebd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00440e50(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = DAT_0068021c;
  if (0 < DAT_00680220) {
    do {
      if ((*(int *)(DAT_00680b28 + 0xec + *piVar2 * 0x984) == 0xe) ||
         (*(int *)(DAT_00680b28 + *piVar2 * 0x984 + 0xf0) == 0xe)) {
        uVar1 = FUN_00493a20(iVar3);
        return uVar1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < DAT_00680220);
  }
  FUN_004afee0(s__trigger_find_start_position__un_004eccd4);
  return 0;
}

