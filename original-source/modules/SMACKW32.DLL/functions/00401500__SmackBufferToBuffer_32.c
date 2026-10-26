/*
 * _SmackBufferToBuffer@32 at 00401500
 * undefined __stdcall _SmackBufferToBuffer@32(int * param_1, ushort param_2, uint param_3, int * param_4, ushort param_5, uint param_6, uint param_7, uint param_8)
 * Address ranges: 00401500-004015e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackBufferToBuffer_32
               (int *param_1,ushort param_2,uint param_3,int *param_4,ushort param_5,uint param_6,
               uint param_7,uint param_8)

{
  int iVar1;
  
                    /* 0x1500  10  _SmackBufferToBuffer@32 */
  if ((param_1 != (int *)0x0) && (param_4 != (int *)0x0)) {
    if (*param_1 == 0) {
      if (*param_4 == 0) {
        iVar1 = param_4[6] - (param_7 & 0xffff);
      }
      else {
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - 1;
        iVar1 = -((param_7 & 0xffff) + param_4[6]);
      }
    }
    else {
      param_3 = (*(ushort *)(param_1 + 5) - param_3) - param_8;
      if (*param_4 == 0) {
        param_6 = (param_6 + param_8) - 1;
        iVar1 = -((param_7 & 0xffff) + param_4[6]);
      }
      else {
        iVar1 = param_4[6] - (param_7 & 0xffff);
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - param_8;
      }
    }
    FUN_004065a0(param_1[0x112],param_1[6] - (param_7 & 0xffff),param_4[0x112],iVar1,
                 param_7 & 0xffff,param_8 & 0xffff,(uint)param_2 + param_1[6] * (param_3 & 0xffff),
                 (uint)param_5 + param_4[6] * (param_6 & 0xffff));
  }
  return;
}

