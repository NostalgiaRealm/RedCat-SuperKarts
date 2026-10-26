/*
 * FUN_00417eb0 at 00417eb0
 * undefined FUN_00417eb0(void)
 * Address ranges: 00417eb0-00417ee6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00417eb0(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  ppuVar2 = &PTR_s_RedCat_004d2504;
  do {
    iVar1 = __strcmpi(*ppuVar2,param_1);
    if (iVar1 == 0) {
      return iVar3;
    }
    ppuVar2 = ppuVar2 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)ppuVar2 < 0x4d252c);
  return -1;
}

