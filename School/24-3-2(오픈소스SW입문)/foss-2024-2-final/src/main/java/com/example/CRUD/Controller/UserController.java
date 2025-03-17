package com.example.CRUD.Controller;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import com.example.CRUD.Service.UserService;
import com.example.CRUD.model.User;

@Controller
public class UserController {

    @Autowired private UserService userService;
    
    @GetMapping("/create")
    public String GoCreate() {
        return "create";
    }

    @GetMapping("/read")
    public String GoRead() {
        return "read";
    }

    @GetMapping("/update")
    public String GoUpdate(Model model) {
        List<User> users = userService.findAll(); 
        model.addAttribute("users", users);
        return "update";
    }

    @GetMapping("/delete")
    public String GoDelete(Model model) {
        List<User> users = userService.findAll(); 
        model.addAttribute("users", users);
        return "delete";
    }
    
    @PostMapping("/create")
    public String CreateUser(User user) {
        userService.Create(user);
        return "create";
    }

    @PostMapping("/read")
    public String ReadUser(String userName, Model model) {
        Optional<User> user = userService.findByUserName(userName);
        if (user.isPresent()) {
            model.addAttribute("user", user.get());
        } else {
            model.addAttribute("error", "찾는 이름이 없습니다.");
        }
        return "read";
    }

    @PostMapping("/update")
    public String UpdateUser(User updateUser) {
        userService.UpdateById(updateUser);
        return "redirect:/update";
    }

    @PostMapping("/delete/{id}")
    public String DeleteUser(@PathVariable long id) {
        userService.DeleteById(id);
        return "redirect:/delete";
    }
    
}
