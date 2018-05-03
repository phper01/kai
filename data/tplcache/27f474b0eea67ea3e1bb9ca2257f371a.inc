<li><a class="hide" href="{dede:field name='typeurl'/}">{dede:field name='typename'/}</a>
    <ul>
        
            
            {dede:sql sql='Select * from dede_arctype where reid=~id~'}
            <li><a href='[field:typedir function='str_replace("{cmspath}","",@me)'/]'>[field:typename/]</a></li>
            {/dede:sql}
    </ul>

</li>