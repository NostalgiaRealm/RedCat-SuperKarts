/*
 * FUN_0043ec64 at 0043ec64
 * undefined __register FUN_0043ec64(int * param_1, uint param_2, undefined4 param_3)
 * Address ranges: 0043ec64-0043ecf7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ec64(int *param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint uVar2;
  char cVar3;
  bool bVar4;
  
  cVar1 = *(char *)((int)param_1 + 0x4b);
  cVar3 = (char)param_2;
  uVar2 = param_2;
  if (cVar3 != cVar1) {
    *(char *)((int)param_1 + 0x4b) = cVar3;
    FUN_0043eaa4((int)param_1,(&DAT_0047b900)[param_2 & 0xff]);
    param_3 = extraout_ECX;
    uVar2 = extraout_EDX;
    if (((*(byte *)(param_1 + 8) & 1) == 0) &&
       (((*(byte *)(param_1 + 8) & 0x10) == 0 || (param_1[9] != 0)))) {
      bVar4 = (byte)(cVar3 - 3U) < 2;
      if (((byte)(cVar1 - 1U) < 2 == bVar4) &&
         ((((cVar1 != '\0' && (cVar1 != '\x05')) && (cVar3 != '\0')) && (cVar3 != '\x05')))) {
        (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_1[0xd],param_1[0xe],param_1[0xf]);
        param_3 = extraout_ECX_00;
        uVar2 = extraout_EDX_00;
      }
      else {
        FUN_00403088(param_1,CONCAT31((int3)(param_2 >> 8),bVar4),extraout_ECX);
        param_3 = extraout_ECX_01;
        uVar2 = extraout_EDX_01;
      }
    }
  }
  FUN_00403088(param_1,uVar2,param_3);
  return;
}

