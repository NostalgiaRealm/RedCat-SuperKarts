/*
 * FUN_0040e0c0 at 0040e0c0
 * undefined FUN_0040e0c0(void)
 * Address ranges: 0040e0c0-0040e141
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040e0c0(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_18 [4];
  int local_8;
  int local_4;
  
  cVar1 = FUN_0040e030(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_004be6c9();
    uVar2 = uVar2 & 0x80000001;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
    }
    iVar3 = param_2 * 0x50 + DAT_00680ae0;
    local_18[2] = param_2;
    local_4 = param_2;
    local_18[0] = *(int *)(iVar3 + 0x1c);
    local_18[1] = *(undefined4 *)(iVar3 + 0x18);
    local_8 = local_18[0];
    local_18[3] = local_18[1];
    iVar3 = 0;
    piVar4 = local_18 + uVar2 * 3;
    do {
      if (*piVar4 != -1) {
        return local_18[iVar3 + uVar2 * 3];
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < 3);
  }
  return param_2;
}

