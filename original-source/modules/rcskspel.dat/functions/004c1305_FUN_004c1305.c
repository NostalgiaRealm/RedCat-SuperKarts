/*
 * FUN_004c1305 at 004c1305
 * undefined FUN_004c1305(void)
 * Address ranges: 004c1305-004c1360
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c1305(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    iVar3 = *param_1 - param_1[2];
    if (0 < iVar3) {
      iVar1 = FUN_004c37d3(param_1[4],param_1[2],iVar3);
      if (iVar1 == iVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}

