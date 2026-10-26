/*
 * FUN_00407d7c at 00407d7c
 * undefined __register FUN_00407d7c(undefined * param_1, int * param_2)
 * Address ranges: 00407d7c-00407dae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407d7c(undefined *param_1,int *param_2)

{
  uint cchLength;
  undefined4 *puVar1;
  
  cchLength = FUN_00403dd0((int)param_1);
  puVar1 = (undefined4 *)FUN_00403f94(param_1);
  FUN_00403c38(param_2,puVar1,cchLength);
  if (0 < (int)cchLength) {
    CharLowerBuffA((LPSTR)*param_2,cchLength);
  }
  return;
}

