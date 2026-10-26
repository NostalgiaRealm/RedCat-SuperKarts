/*
 * FUN_0040286c at 0040286c
 * byte * __register FUN_0040286c(byte * param_1, int * param_2)
 * Address ranges: 0040286c-004028e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_0040286c(byte *param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *local_1008 [1024];
  
  pbVar3 = param_1;
  while( true ) {
    for (; (*pbVar3 != 0 && (*pbVar3 < 0x21)); pbVar3 = pbVar3 + 1) {
    }
    if ((*pbVar3 != 0x22) || (pbVar3[1] != 0x22)) break;
    pbVar3 = pbVar3 + 2;
  }
  uVar2 = 0;
  local_1008[0] = param_1;
  while ((bVar1 = *pbVar3, 0x20 < bVar1 && ((int)uVar2 < 0x1000))) {
    pbVar4 = pbVar3;
    if (bVar1 == 0x22) {
      while( true ) {
        pbVar3 = pbVar4 + 1;
        bVar1 = *pbVar3;
        if ((bVar1 == 0) || (bVar1 == 0x22)) break;
        *(byte *)((int)local_1008 + uVar2) = bVar1;
        uVar2 = uVar2 + 1;
        pbVar4 = pbVar3;
      }
      if (*pbVar3 != 0) {
        pbVar3 = pbVar4 + 2;
      }
    }
    else {
      *(byte *)((int)local_1008 + uVar2) = bVar1;
      uVar2 = uVar2 + 1;
      pbVar3 = pbVar3 + 1;
    }
  }
  FUN_00403c38(param_2,local_1008,uVar2);
  return pbVar3;
}

