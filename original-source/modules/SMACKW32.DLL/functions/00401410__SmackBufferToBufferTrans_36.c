/*
 * _SmackBufferToBufferTrans@36 at 00401410
 * undefined8 __stdcall _SmackBufferToBufferTrans@36(int * param_1, ushort param_2, uint param_3, int * param_4, ushort param_5, uint param_6, uint param_7, uint param_8, char param_9)
 * Address ranges: 00401410-004014fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8
_SmackBufferToBufferTrans_36
          (int *param_1,ushort param_2,uint param_3,int *param_4,ushort param_5,uint param_6,
          uint param_7,uint param_8,char param_9)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
                    /* 0x1410  11  _SmackBufferToBufferTrans@36 */
  uVar3 = CONCAT44(param_6,param_4);
  if ((param_1 != (int *)0x0) && (uVar3 = CONCAT44(param_6,param_4), param_4 != (int *)0x0)) {
    if (*param_1 == 0) {
      if (*param_4 == 0) {
        iVar2 = param_4[6] - (param_7 & 0xffff);
      }
      else {
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - 1;
        iVar2 = -((param_7 & 0xffff) + param_4[6]);
      }
    }
    else {
      param_3 = (*(ushort *)(param_1 + 5) - param_3) - param_8;
      if (*param_4 == 0) {
        param_6 = (param_6 + param_8) - 1;
        iVar2 = -((param_7 & 0xffff) + param_4[6]);
      }
      else {
        iVar2 = param_4[6] - (param_7 & 0xffff);
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - param_8;
      }
    }
    uVar1 = param_7 & 0xffff;
    uVar3 = FUN_004065df(param_4[0x112],uVar1,param_1[0x112],param_1[6] - uVar1,param_4[0x112],iVar2
                         ,uVar1,param_8 & 0xffff,(param_3 & 0xffff) * param_1[4] + (uint)param_2,
                         (uint)param_5 + param_4[6] * (param_6 & 0xffff),param_9);
  }
  return uVar3;
}

