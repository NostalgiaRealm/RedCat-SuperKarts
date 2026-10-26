/*
 * FUN_0043a918 at 0043a918
 * undefined __register FUN_0043a918(undefined4 * param_1, int * param_2)
 * Address ranges: 0043a918-0043a9ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a918(undefined4 *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  FUN_00403ba4(param_2,param_1);
  iVar3 = 1;
  do {
    iVar2 = FUN_00403dd0(*param_2);
    if (iVar2 < iVar3) {
      return;
    }
    bVar1 = *(byte *)(*param_2 + -1 + iVar3);
    if (((byte)PTR_DAT_0047c9c8[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0) {
      if (bVar1 == 0x26) {
        if ((PTR_DAT_0047c9d8[8] != '\0') && (1 < iVar3)) {
          iVar2 = FUN_00403dd0(*param_2);
          if ((1 < iVar2 - iVar3) &&
             ((*(char *)(*param_2 + -2 + iVar3) == '(' && (*(char *)(*param_2 + 1 + iVar3) == ')')))
             ) {
            FUN_00404018(param_2,iVar3 + -1,4);
            goto LAB_0043a99f;
          }
        }
        FUN_00404018(param_2,iVar3,1);
      }
    }
    else {
      iVar3 = iVar3 + 1;
    }
LAB_0043a99f:
    iVar3 = iVar3 + 1;
  } while( true );
}

