/*
 * FUN_00411618 at 00411618
 * undefined __register FUN_00411618(int * param_1, int param_2, undefined4 * param_3)
 * Address ranges: 00411618-0041165c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411618(int *param_1,int param_2,undefined4 *param_3)

{
  if ((char)param_1[6] != '\0') {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c78c,0);
  }
  if ((param_2 < 0) || (param_1[4] < param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  FUN_00411660(param_1,param_2,param_3);
  return;
}

