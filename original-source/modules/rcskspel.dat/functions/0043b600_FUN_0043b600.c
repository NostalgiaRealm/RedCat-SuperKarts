/*
 * FUN_0043b600 at 0043b600
 * undefined FUN_0043b600(void)
 * Address ranges: 0043b600-0043b657
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043b600(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  FUN_004371f0();
  cVar1 = FUN_00437550();
  if (cVar1 != '\0') {
    iVar2 = FUN_0043b5b0(param_1);
    if (iVar2 == -1) {
      FUN_004afee0(s__s___d__Static_sample__s_not_fou_004ec2ec,
                   s_D__work_rcsk_Code_game_snd_main__004ec2c8,0xc5,param_1);
    }
    FUN_0049dd20(iVar2);
    FUN_0049d780(param_2);
  }
  return;
}

