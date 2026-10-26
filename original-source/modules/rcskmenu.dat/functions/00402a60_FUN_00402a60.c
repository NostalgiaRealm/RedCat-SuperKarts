/*
 * FUN_00402a60 at 00402a60
 * int __register FUN_00402a60(byte * param_1, byte * param_2)
 * Address ranges: 00402a60-00402ae1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00402a60(byte *param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  uVar2 = (uint)*param_2;
  pbVar4 = param_1 + 1;
  pbVar5 = param_2 + 1;
  iVar1 = *param_1 - uVar2;
  if (*param_1 < uVar2 || iVar1 == 0) {
    uVar2 = uVar2 + iVar1;
  }
  uVar3 = uVar2 >> 2;
  do {
    if (uVar3 == 0) {
LAB_00402aa3:
      uVar2 = uVar2 & 3;
      if ((uVar2 == 0) ||
         ((*pbVar4 == *pbVar5 &&
          ((uVar2 == 1 || ((pbVar4[1] == pbVar5[1] && ((uVar2 == 2 || (pbVar4[2] == pbVar5[2])))))))
          ))) {
        iVar1 = iVar1 * 2;
      }
      return iVar1;
    }
    if (*(int *)pbVar4 != *(int *)pbVar5) {
      return iVar1;
    }
    if (uVar3 == 1) {
      pbVar4 = pbVar4 + 4;
      pbVar5 = pbVar5 + 4;
      goto LAB_00402aa3;
    }
    if (*(int *)(pbVar4 + 4) != *(int *)(pbVar5 + 4)) {
      return iVar1;
    }
    pbVar4 = pbVar4 + 8;
    pbVar5 = pbVar5 + 8;
    uVar3 = uVar3 - 2;
  } while( true );
}

