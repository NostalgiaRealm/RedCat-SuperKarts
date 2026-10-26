/*
 * FUN_004cb4e3 at 004cb4e3
 * undefined FUN_004cb4e3(void)
 * Address ranges: 004cb4e3-004cb555
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_004cb4e3(byte *param_1,uint param_2)

{
  ushort uVar1;
  byte *pbVar2;
  
  if (DAT_006b6b7c == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
    return pbVar2;
  }
  while( true ) {
    uVar1 = (ushort)*param_1;
    if (uVar1 == 0) break;
    if ((*(byte *)((int)&DAT_006b6c80 + uVar1 + 1) & 4) == 0) {
      pbVar2 = param_1;
      if (param_2 == uVar1) break;
    }
    else {
      pbVar2 = param_1 + 1;
      if (param_1[1] == 0) {
        return (byte *)0x0;
      }
      if (param_2 == CONCAT11(*param_1,param_1[1])) {
        return param_1;
      }
    }
    param_1 = pbVar2 + 1;
  }
  return (byte *)(~-(uint)(param_2 != uVar1) & (uint)param_1);
}

