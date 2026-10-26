/*
 * FUN_004187b0 at 004187b0
 * undefined __register FUN_004187b0(int * param_1, undefined * param_2, LPSIZE param_3)
 * Address ranges: 004187b0-004187ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004187b0(int *param_1,undefined *param_2,LPSIZE param_3)

{
  int c;
  LPCSTR lpString;
  
  FUN_00418a68(param_1,3);
  param_3->cx = 0;
  param_3->cy = 0;
  c = FUN_00403dd0((int)param_2);
  lpString = FUN_00403f94(param_2);
  GetTextExtentPoint32A((HDC)param_1[1],lpString,c,param_3);
  return;
}

