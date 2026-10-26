/*
 * FUN_00497ab0 at 00497ab0
 * undefined FUN_00497ab0(void)
 * Address ranges: 00497ab0-00497b24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00497ab0(int param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6
                 )

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00680b2c;
  if ((param_1 < 0) || (DAT_00680b2c < param_1)) {
    FUN_004afee0(s__calc_start_and_end_chunk__illeg_004fb30c,param_1);
  }
  iVar3 = iVar2 + 1;
  iVar4 = param_1;
  if (param_1 < 0) {
    iVar4 = 0;
  }
  if (iVar2 <= iVar4) {
    iVar4 = iVar2 + -1;
  }
  param_2 = param_2 + param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  bVar1 = iVar2 <= param_2;
  if (bVar1) {
    iVar3 = param_2 - iVar2;
    param_2 = iVar2 + -1;
  }
  *param_3 = iVar4;
  *param_4 = param_2;
  *param_5 = 0;
  *param_6 = iVar3;
  return bVar1;
}

